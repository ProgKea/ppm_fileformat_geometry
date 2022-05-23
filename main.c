#include <stdio.h>
#include <sys/types.h>

#define WIDTH 100
#define HEIGHT 100

typedef struct RGB {
  uint r;
  uint g;
  uint b;
} RGB;

typedef struct coordinates {
  int x;
  int y;
} coordinates;

coordinates get_midpoint(coordinates first_point, coordinates second_point) {
  return (coordinates){(first_point.x ^ 2 + second_point.x ^ 2) / 2,
                       (first_point.y ^ 2 + second_point.y ^ 2) / 2};
}

void circle_hollow(RGB pixels[], uint radius, uint width,
                               uint height) {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {

    }
  }
}

void save_as_ppm(const char *file_path, uint width, uint height, RGB pixels[]) {
  FILE *file = fopen(file_path, "w");
  fprintf(file, "P3\n%u %u \n255\n", width, height);

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      fprintf(file, "%i\t%i\t%i\n", pixels[j].r, pixels[j].g, pixels[j].b);
    }
  }
}

int main() {
  RGB circle[WIDTH * HEIGHT];
  circle_hollow(circle, 100, WIDTH, HEIGHT);
  save_as_ppm("output.ppm", HEIGHT, HEIGHT, circle);

  return 0;
}
