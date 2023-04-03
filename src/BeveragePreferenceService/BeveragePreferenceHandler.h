#ifndef VENDING_MACHINE_MICROSERVICES_WEATHERHANDLER_H
#define VENDING_MACHINE_MICROSERVICES_WEATHERHANDLER_H

#include <iostream>
#include <string>
#include <regex>
#include <future>

#include "../../gen-cpp/BeveragePreferenceService.h"

#include "../ClientPool.h"
#include "../ThriftClient.h"
#include "../logger.h"

namespace vending_machine
{

  class BeveragePreferenceServiceHandler : public BeveragePreferenceServiceIf
  {
  public:
    BeveragePreferenceServiceHandler();
    ~BeveragePreferenceServiceHandler() override = default;
    void BeveragePreferenceServiceHandler::getBeverage(std::string& _return, const BeverageType::type btype) override;
  };

  Constructor
  BeveragePreferenceServiceHandler::BeveragePreferenceServiceHandler()
  {
    printf("BeveragePreferenceServiceHandler constructed\n");
  }

  void BeveragePreferenceServiceHandler::getBeverage(std::string& _return, const BeverageType::type btype) {
  {
    // Your implementation goes here
    printf("getBeverage\n");

    if (btype == BeverageType::HOT)
      _return = "cappuccino";
    else
      _return = "lemonade";
  }

} // namespace vending_machine

#endif // VENDING_MACHINE_MICROSERVICES_WEATHERHANDLER_H
