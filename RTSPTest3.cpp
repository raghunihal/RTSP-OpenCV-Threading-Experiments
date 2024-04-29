#include <iostream>
#include <thread>
#include <opencv2/opencv.hpp>

class RTSPVideoWriterObject 
{
  private: cv::VideoCapture capture;
  int frame_width,
  frame_height;
  int codec;
  cv::VideoWriter output_video;
  std::thread thread;
  bool status;
  cv::Mat frame;

  void update() 
  {
    while (true) 
    {
      if (capture.isOpened()) 
      {
        capture.read(frame);
      }
    }
  }

  public: RTSPVideoWriterObject(const std::string & src) 
  {
    capture.open(src);

    frame_width = capture.get(cv::CAP_PROP_FRAME_WIDTH);
    frame_height = capture.get(cv::CAP_PROP_FRAME_HEIGHT);

    codec = cv::VideoWriter::fourcc('M', 'J', 'P', 'G');
    output_video.open("output.avi", codec, 30, cv::Size(frame_width, frame_height));

    thread = std::thread( & RTSPVideoWriterObject::update, this);
    thread.detach();
  }

  void show_frame() 
  {
    if (status) 
    {
      cv::imshow("frame", frame);
    }

    int key = cv::waitKey(1);
    if (key == 'q') 
    {
      capture.release();
      output_video.release();
      cv::destroyAllWindows();
      std::exit(1);
    }
  }

  void save_frame() 
  {
    output_video.write(frame);
  }
};

int main() 
{
  std::string rtsp_stream_link = "your stream link!";
  RTSPVideoWriterObject video_stream_widget(rtsp_stream_link);

  while (true) 
  {
    try 
    {
      video_stream_widget.show_frame();
      video_stream_widget.save_frame();
    } 
    catch (const std::exception & e) 
    {
      std::cerr << e.what() << std::endl;
    }
  }

  return 0;
}
