#ifndef _SOCIAL_BEHAVIOUR_H_
#define _SOCIAL_BEHAVIOUR_H_

#include "behaviour_base.h"

class social_behaviour:public behaviour_base
{
 public:
  social_behaviour(uint32_t l_x, uint32_t l_y);
  void choose_next_pos(const std::vector<behaviour_base *> & p_others,environment & p_environment);
  static void set_class_color(uint32_t p_color);
 private:
  static uint32_t m_class_colour; 
};
#endif /* _SOCIAL_BEHAVIOUR_H_ */