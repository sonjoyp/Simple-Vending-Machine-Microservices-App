#ifndef VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H
#define VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H

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

    void getBeverage(std::string &_return, const BeverageType::type btype);
  };

  // Constructor
  BeveragePreferenceServiceHandler::BeveragePreferenceServiceHandler()
  {
  }

  void BeveragePreferenceServiceHandler::getBeverage(std::string &_return, const BeverageType::type btype)
  {
    // Your implementation goes here
    printf("GetBeveragePreference\n");

    int randomNumberForBeverage = rand() % 3;
    if (btype == BeverageType::type::COLD)
    {
      if (randomNumberForBeverage == 0)
        _return = "lemonade";
      else if (randomNumberForBeverage == 1)
        _return = "ice tea";
      else if (randomNumberForBeverage == 2)
        _return = "soda";
    }
    else
    {
      if (randomNumberForBeverage == 0)
        _return = "cappuccino";
      else if (randomNumberForBeverage == 1)
        _return = "latte";
      else if (randomNumberForBeverage == 2)
        _return = "espresso";
    }
    return;
  }

} // namespace vending_machine

#endif // VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H