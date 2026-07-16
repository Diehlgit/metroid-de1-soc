"""
generate_sprites.py
Lê todos os diretórios de entidades/tiles/itens e gera [nome]_sprites.h
para cada um.

Uso:
    cd mapas/entidades && python3 generate_sprites.py
    cd mapas/tiles     && python3 generate_sprites.py
    cd mapas/itens     && python3 generate_sprites.py

Estrutura esperada por entidade:
    <nome>/
        states/
            <estado>/
                <movimento>/
                    00.png, 01.png, ...
"""

from PIL import Image
from pathlib import Path

ROOT = Path(".")

def to_rgb565(r, g, b):
    return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3)

def gen_pixels(path, name):
    img = Image.open(path).convert("RGBA")
    w, h = img.size
    lines = [f"static const uint16_t {name}_PIXELS[{w * h}] = {{"]
    for y in range(h):
        row = []
        for x in range(w):
            r, g, b, a = img.getpixel((x, y))
            row.append("0x8001" if a < 128 else f"0x{to_rgb565(r,g,b):04X}")
        lines.append("    " + ", ".join(row) + ",")
    lines.append("};")
    return lines, w, h

def process_entity(ent_dir: Path):
    name = ent_dir.name
    output = ent_dir / f"{name}_sprites.h"
    states_path = ent_dir / "states"

    if not states_path.exists():
        return

    lines = [
        "/* AUTO-GERADO por generate_sprites.py — não edite */",
        "#pragma once",
        '#include "../../../include/entity.h"',
        "",
    ]

    for state_dir in sorted(states_path.iterdir()):
        if not state_dir.is_dir() or state_dir.name.startswith("."): continue

        for move_dir in sorted(state_dir.iterdir()):
            if not move_dir.is_dir() or move_dir.name.startswith("."): continue

            sprites = sorted(p for p in move_dir.iterdir() if p.suffix == ".png")
            sprite_names = []

            for sprite in sprites:
                sname = f"{state_dir.name.upper()}_{move_dir.name.upper()}_{sprite.stem}"
                sprite_names.append(sname)
                pxl_lines, w, h = gen_pixels(sprite, sname)
                lines += pxl_lines
                lines += [
                    f"static Sprite {sname} = {{",
                    f"    .height={h}, .width={w},",
                    f"    .pixels=(uint16_t*){sname}_PIXELS",
                    f"}};",
                    "",
                ]

            frames_name = f"{state_dir.name}_{move_dir.name}_frames"
            anim_name   = f"anim_{state_dir.name}_{move_dir.name}"

            lines += [f"static Sprite *{frames_name}[] = {{"]
            for sn in sprite_names:
                lines.append(f"    &{sn},")
            lines += ["};", ""]

            lines += [
                f"static Animation {anim_name} = {{",
                f"    .frames         = {frames_name},",
                f"    .frame_count    = {len(sprite_names)},",
                f"    .frame_duration = 6,",
                f"    .loops          = 0,",
                f"}};",
                "",
            ]

    output.write_text("\n".join(lines) + "\n")
    print(f"  {output}")

def main():
    ents = sorted(e for e in ROOT.iterdir() if e.is_dir() and not e.name.startswith("."))
    if not ents:
        print("Nenhum diretório encontrado.")
        return
    print("Gerando sprites.h:")
    for e in ents:
        process_entity(e)

if __name__ == "__main__":
    main()
