#include "MJPEGWriter.h"
int
main()
{
    MJPEGWriter test(8081);

    VideoCapture cap;
    bool ok = cap.open(0);
    if (!ok)
    {
        printf("no cam found ;(.\n");
        pthread_exit(NULL);
    }
    Mat frame;
    cap >> frame;
    test.write(frame);
    frame.release();
    test.start();
    int ster = -1;
    while(cap.isOpened() /*&& ster==-1*/){
      cap >> frame; 
      test.write(frame); 
      //imshow("frame", frame);
      frame.release();
      //ster = waitKey(1);
    }
    
    test.stop();
    exit(0);

}
