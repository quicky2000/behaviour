#include "erratic_behaviour.h"
#include <stdlib.h>

erratic_behaviour::erratic_behaviour(uint32_t l_x, uint32_t l_y):
  behaviour_base(l_x,l_y,m_class_colour)
{
  reset();
}

void erratic_behaviour::choose_next_pos(const std::vector<behaviour_base *> & p_others,environment & p_environment)
{
  
  std::pair<uint32_t,uint32_t> l_new_pos = get_pos();
  bool l_ok = false;
  if(!m_counter) reset();
  uint32_t l_new_x;
  uint32_t l_new_y;
  do
    {
      l_new_x = l_new_pos.first + m_delta_x;
      l_new_y = l_new_pos.second + m_delta_y;
      l_ok =  l_new_x >= 0 && l_new_x < behaviour_base::m_width && l_new_y >= 0 && l_new_y < behaviour_base::m_height ;
      if(!l_ok) reset();
    }
  while(!l_ok);
  --m_counter;

l_new_pos.first = l_new_x;
l_new_pos.second = l_new_y;
  set_new_pos(l_new_pos);
}

void erratic_behaviour::reset(void)
{
  m_delta_x = (int)(3 * ((float)rand())/RAND_MAX) -1 ;
  m_delta_y = (int)(3 * ((float)rand())/RAND_MAX) -1 ;
  m_counter= 10 + (int)(100 * ((float)rand())/RAND_MAX);
}

void erratic_behaviour::set_class_color(uint32_t p_color)
{
  m_class_colour = p_color;
}

uint32_t erratic_behaviour::m_class_colour = 0;
//EOF
