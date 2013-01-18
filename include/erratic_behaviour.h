#ifndef _ERRATIC_BEHAVIOUR_H_
#define _ERRATIC_BEHAVIOUR_H_

#include "behaviour_base.h"

class erratic_behaviour:public behaviour_base
{
 public:
  erratic_behaviour(uint32_t l_x, uint32_t l_y);
  void choose_next_pos(const std::vector<behaviour_base *> & p_others,environment & p_environment);
  static void set_class_color(uint32_t p_color);
 private:
  void reset(void);
  int m_delta_x;
  int m_delta_y;
  unsigned int m_counter;
  static uint32_t m_class_colour;
};
#endif /* _ERRATIC_BEHAVIOUR_H_ */
