#include <math.h>
#include <stdio.h>
#include <sys/types.h>

#define WIDTH 500
#define HEIGHT 500

typedef struct coordinates {
  int x;
  int y;
} coordinates;

typedef struct RGB {
  uint r;
  uint g;
  uint b;
} RGB;

void rectangle_line(RGB pixels[], uint size, uint width, uint height,
                    RGB primary_color, RGB secondary_color) {
  coordinates center = (coordinates){width / 2, height / 2};
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int dx = center.x - x;
      int dy = center.y - y;

      if ((dx ^ 2 + dy ^ 2) < (size ^ 2)) {
        pixels[y * width + x] = primary_color;
      } else {
        pixels[y * width + x] = secondary_color;
      }
    }
  }
}

void circle(RGB pixels[], uint radius, uint width, uint height,
            RGB primary_color, RGB secondary_color) {
  coordinates center = (coordinates){width / 2, height / 2};
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int dx = center.x - x;
      int dy = center.y - y;

      if ((dx * dx + dy * dy) <= ((int)radius * (int)radius)) {
        pixels[y * width + x] = primary_color;
      } else {
        pixels[y * width + x] = secondary_color;
      }
    }
  }
}

void checker_pattern(RGB pixels[], uint size, uint width, uint height,
            RGB primary_color, RGB secondary_color) {
  coordinates center = (coordinates){width / 2, height / 2};
  for (int y = 0; y < height; y++) {
    if ((y % size * 2) >= size) {
      for (int x = 0; x < width; x++) {
        if ((x % size * 2) < size) pixels[y * width + x] = primary_color;
        else pixels[y * width + x] = secondary_color;
      }
    }
    else {
      for (int x = 0; x < width; x++) {
        if ((x % size * 2) >= size) pixels[y * width + x] = primary_color;
        else pixels[y * width + x] = secondary_color;
      }
    }
  }
}

void save_as_ppm(const char *file_path, uint width, uint height, RGB pixels[]) {
  FILE *file = fopen(file_path, "w");
  fprintf(file, "P3\n%u %u \n255\n", width, height);
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      fprintf(file, "%u %u %u\n", pixels[y * width + x].r,
              pixels[y * width + x].g, pixels[y * width + x].b);
    }
  }
}

int main() {
  RGB pixels[WIDTH * HEIGHT];

  circle(pixels, WIDTH / 2, WIDTH, HEIGHT, (RGB){0, 0, 255}, (RGB){0, 0, 0});
  save_as_ppm("circle.ppm", WIDTH, HEIGHT, pixels);

  rectangle_line(pixels, 20, WIDTH, HEIGHT, (RGB){0, 255, 0}, (RGB){0, 0, 0});
  save_as_ppm("rectangle_line.ppm", WIDTH, HEIGHT, pixels);

  checker_pattern(pixels, WIDTH/10, WIDTH, HEIGHT, (RGB){237, 214, 180}, (RGB){175, 132, 98});
  save_as_ppm("checker_pattern.ppm", WIDTH, HEIGHT, pixels);

  return 0;
}
