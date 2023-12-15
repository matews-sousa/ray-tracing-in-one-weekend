#include <iostream>
#include "vec3.h"
#include "color.h"

int main() {
  int image_width = 256;
  int image_height = 256;

  std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

  for (int j = 0; j < image_height; ++j) {
    std::clog << "\rScanlines remaining: " << (image_height - j) << " " << std::flush;
    for (int i = 0; i < image_width; ++i) {
      double r = double(i) / (image_width - 1);
      double g = double(j) / (image_height - 1);
      double b = 0;
      color pixel_color = color(r, g, b);
      write_color(std::cout, pixel_color);
    }
  }

  std::clog << "\nDone.\n";
  
  return 0;
}