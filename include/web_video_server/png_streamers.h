#ifndef PNG_STREAMERS_H_
#define PNG_STREAMERS_H_

#include <image_transport/image_transport.h>
#include "web_video_server/image_streamer.h"
#include "async_web_server_cpp/http_request.hpp"
#include "async_web_server_cpp/http_connection.hpp"

namespace web_video_server
{

class PngStreamer : public ImageStreamer
{
public:
  PngStreamer(const async_web_server_cpp::HttpRequest &request, async_web_server_cpp::HttpConnectionPtr connection,
                image_transport::ImageTransport it);
  ~PngStreamer();
protected:
  virtual void sendImage(const cv::Mat &, const ros::WallTime &time);

private:
  int quality_;
};

class PngStreamerType : public ImageStreamerType
{
public:
  boost::shared_ptr<ImageStreamer> create_streamer(const async_web_server_cpp::HttpRequest &request,
                                                   async_web_server_cpp::HttpConnectionPtr connection,
                                                   image_transport::ImageTransport it);

  std::string create_viewer(const async_web_server_cpp::HttpRequest &request);
};

class PngSnapshotStreamer : public ImageStreamer
{
public:
  PngSnapshotStreamer(const async_web_server_cpp::HttpRequest &request,
                       async_web_server_cpp::HttpConnectionPtr connection, image_transport::ImageTransport it);

  ~PngSnapshotStreamer();
protected:
  virtual void sendImage(const cv::Mat &, const ros::WallTime &time);

private:
  int quality_;
};

}

#endif
