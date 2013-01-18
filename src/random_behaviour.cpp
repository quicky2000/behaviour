#include "random_behaviour.h"
#include <stdlib.h>

random_behaviour::random_behaviour(uint32_t l_x, uint32_t l_y):
  behaviour_base(l_x,l_y,m_class_colour)
{
}

void random_behaviour::choose_next_pos(const std::vector<behaviour_base *> & p_others,environment & p_environment)
{
  std::pair<uint32_t,uint32_t> l_new_pos = get_pos();
  int l_delta_x = (int)(3 * ((float)rand())/RAND_MAX) -1 ;
  int l_delta_y = (int)(3 * ((float)rand())/RAND_MAX) -1 ;
  uint32_t l_new_x = l_new_pos.first + l_delta_x;
  uint32_t l_new_y = l_new_pos.second + l_delta_y;
  if( l_new_x >= 0 && l_new_x < behaviour_base::m_width) l_new_pos.first = l_new_x;
  if( l_new_y >= 0 && l_new_y < behaviour_base::m_height) l_new_pos.second = l_new_y;
  set_new_pos(l_new_pos);
}

void random_behaviour::set_class_color(uint32_t p_color)
{
  m_class_colour = p_color;
}

uint32_t random_behaviour::m_class_colour = 0;
//EOF
