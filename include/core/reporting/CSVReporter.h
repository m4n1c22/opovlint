/*
 * CSVReporter.h
 *
 *  Created on: May 18, 2014
 *      Author: ahueck
 */

#ifndef CORE_REPORTING_CSVREPORTER_H
#define CORE_REPORTING_CSVREPORTER_H

#include "IssueReporter.h"

namespace opov {

class CSVReporter : public opov::IssueReporter {
 public:
  CSVReporter();
  void addIssue(const TranslationUnitIssues& issue) override;
  void addIssues(const TUIssuesMap& issues) override;
  void addIssues(const std::vector<filter::SingleIssue>& issues) override;
  ~CSVReporter() override;

 private:
  void print(const TranslationUnitIssues& issue);
};

} /* namespace opov */

#endif  // CORE_REPORTING_CSVREPORTER_H
