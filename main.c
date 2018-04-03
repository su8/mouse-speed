#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>

int main(void) {
  Display *display = XOpenDisplay(NULL);
  int acc_num = 0, acc_denom = 0, threshold = 0;

  if (NULL == display) {
    printf("%s\n", "Cannot open X server");
    return EXIT_FAILURE;
  }

  XGetPointerControl(display, &acc_num, &acc_denom, &threshold);
  printf("%d%%\n", (110 - threshold));
  XCloseDisplay(display);

  return EXIT_SUCCESS;
}
