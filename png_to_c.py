import sys
from PIL import Image

def rgb888_to_rgb565(r, g, b):
    """Converts 8-bit R, G, B channels to 16-bit RGB565."""
    r5 = (r >> 3) & 0x1F
    g6 = (g >> 2) & 0x3F
    b5 = (b >> 3) & 0x1F
    return (r5 << 11) | (g6 << 5) | b5

def convert_image(image_path, array_name):
    try:
        img = Image.open(image_path).convert('RGB') 
    except IOError:
        print(f"Error: Could not open {image_path}")
        return

    width, height = img.size
    pixels = img.load()

    print(f"/* Auto-generated from {image_path} ({width}x{height}) */")
    print(f"const color_t {array_name}[{width * height}] = {{")

    for y in range(height):
        row_hex = []
        for x in range(width):
            r, g, b = pixels[x, y]
            
            # --- TRANSPARENCY CHECK ---
            # If the pixel is 0x808080 (128, 128, 128), replace with Magenta
            if r == 128 and g == 128 and b == 128:
                rgb565 = 0xF81F # RGB565 for pure Magenta
            else:
                rgb565 = rgb888_to_rgb565(r, g, b)
                
            row_hex.append(f"0x{rgb565:04X}")
        
        print("    " + ", ".join(row_hex) + ",")

    print("};")
    print("\n")

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python png_to_c.py <image.png> <array_name>")
    else:
        convert_image(sys.argv[1], sys.argv[2])
