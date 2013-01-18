#ifndef _ASOCIAL_BEHAVIOUR2_H_
#define _ASOCIAL_BEHAVIOUR2_H_

#include "behaviour_base.h"

class asocial_behaviour2:public behaviour_base
{
 public:
  asocial_behaviour2(uint32_t l_x, uint32_t l_y);
  void choose_next_pos(const std::vector<behaviour_base *> & p_others,environment & p_environment);
  static void set_class_color(uint32_t p_color);
 private:
  static uint32_t m_class_colour;
};
#endif /* _ASOCIAL_BEHAVIOUR2_H_ */