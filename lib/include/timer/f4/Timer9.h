/*
 * This file is a part of the open source stm32plus library.
 * Copyright (c) 2011,2012,2013,2014 Andy Brown <www.andybrown.me.uk>
 * Please see website for licensing terms.
 */

#pragma once

// ensure the MCU series is correct
#ifndef STM32PLUS_F4
#error This class can only be used with the STM32F4 series
#endif


namespace stm32plus {

  /**
   * Timer9 is a general purpose timer. The template parameters can be used to specify a list
   * of timer features that you want to use.
   */

  template<class... Features>
  class Timer9 : public GeneralPurposeTimer<Timer9<Features...>,PERIPHERAL_TIMER9>,
                 public Features... {

    public:

      /**
       * Helper typedef to get at this type
       */

      typedef Timer9<Features...> TimerType;

      /**
       * Constructor. Start the clocks
       */

      Timer9()
        : GeneralPurposeTimer<TimerType,PERIPHERAL_TIMER9>(TIM9),
          Features(static_cast<Timer&>(*this))... {
      }
  };
}
