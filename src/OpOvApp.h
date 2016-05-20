/*
 * OpOvApp.h
 *
 *  Created on: May 8, 2014
 *      Author: ahueck
 */

#ifndef _SRC_OPOVAPP_H
#define _SRC_OPOVAPP_H

#include <core/Application.h>

#include <string>

class OpOvApp : public opov::Application {
 private:
  std::string config_path;

 protected:
  void loadConfig() override;
  void createReporter() override;
  void createFactory() override;

 public:
  explicit OpOvApp(const std::string& config_path);

  ~OpOvApp() override = default;
};

#endif  // _SRC_OPOVAPP_H
