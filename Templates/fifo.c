#include <stdio.h>
int main() {
  int pageFaults = 0;
  int frames = 3;
  int m, n, s, pages, i;
  
  int no_of_frames, no_of_pages, incomingStream[10];
  printf("Enter number of frames: ");
  scanf("%d", &no_of_frames);
  printf("Enter number of pages: ");
  scanf("%d", &no_of_pages);
  printf("Enter reference string: ");
  for (i = 0; i < no_of_pages; ++i) {
    scanf("%d", &incomingStream[i]);
  }

  pages = sizeof(incomingStream) / sizeof(incomingStream[0]);
  printf("Incoming \t Frame 1 \t Frame 2 \t Frame 3");
  int temp[frames];
  for (m = 0; m < frames; m++) {
    temp[m] = -1;
  }
  for (m = 0; m < pages; m++) {
    s = 0;
    for (n = 0; n < frames; n++) {
      if (incomingStream[m] == temp[n]) {
        s++;
        pageFaults--;
      }
    }
    pageFaults++;

    if ((pageFaults <= frames) && (s == 0)) {
      temp[m] = incomingStream[m];
    } else if (s == 0) {
      temp[(pageFaults - 1) % frames] = incomingStream[m];
    }

    printf("\n");
    printf("%d\t\t\t", incomingStream[m]);
    for (n = 0; n < frames; n++) {
      if (temp[n] != -1)
        printf(" %d\t\t\t", temp[n]);
      else
        printf(" - \t\t\t");
    }
  }
  printf("\nTotal Page Faults:\t%d\n", pageFaults);
  printf("Miss Ratio:\t%d/%d\n", pageFaults, pages);
  printf("Hit Ratio:\t%d/%d\n", pages - pageFaults, pages);
  return 0;
}
