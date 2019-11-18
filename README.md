# CV_FrameworkTests
Some projects convering basic functionality of the OpenCV framework

  * BasicRead_Write - This project covers simple reading and writing images using OpenCVs image matrix object. You can achieve
  the same with OpenGL, but you would have to cast an openGL img buffer into an OpenCV.
  
  * BasicRead_CameraVideo - This project covers opening a video file or a camera connected to your computer and display the contents
  on a graphics window. The camera capture though is painfully slow and not very resource efficient. I would chose using other libraries
  to access the camera and again cast the img to a CV::Mat to then push to the img buffer on the window. 
  
  * BasicFaceRecognition - This project uses a simple haar cascade classifier. It uses front face training data to simply detect human faces 
  which is sufficient for most cases. The program also uses reading from cambera video to do realtime face detection. 
  Note that an xml file is provided that needs to be passed as parameter to the executable. 
