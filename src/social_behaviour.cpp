#include "social_behaviour.h"
#include <stdlib.h>
#include <math.h>
#include <iostream>

social_behaviour::social_behaviour(uint32_t l_x, uint32_t l_y):
  behaviour_base(l_x,l_y,m_class_colour)
{
}

void social_behaviour::choose_next_pos(const std::vector<behaviour_base *> & p_others,environment & p_environment)
{
  std::pair<uint32_t,uint32_t> l_pos = get_pos();
  //std::cout << "My pos = " << l_pos.first << "\t" << l_pos.second << std::endl ;
  uint32_t l_dist_max = UINT32_MAX;
  std::pair<uint32_t,uint32_t> l_nearest_pos,l_other_pos;
  std::vector<behaviour_base *>::const_iterator l_iter = p_others.begin();
  std::vector<behaviour_base *>::const_iterator l_iter_end = p_others.end();
  while(l_iter != l_iter_end)
    {
      l_other_pos = (*l_iter)->get_pos();
      if(l_other_pos != l_pos)
	{
	  uint32_t l_dist = (uint32_t)pow(((int32_t)l_other_pos.first) - ((int32_t)l_pos.first),2) + (uint32_t)pow(((int32_t)l_other_pos.second) - ((int32_t)l_pos.second),2);
	  if(l_dist && l_dist < l_dist_max)
	    {
	      l_dist_max = l_dist;
	      l_nearest_pos = l_other_pos;
	    }
	}
      ++l_iter;
    }
  //std::cout << "nearest neighbour is " << l_nearest_pos.first << "\t" << l_nearest_pos.second << std::endl ;
  l_other_pos = l_pos;

  int l_delta_x = 0;
  if(l_nearest_pos.first > l_pos.first )
    {
      l_delta_x = 1;
    }
  else if(l_nearest_pos.first < l_pos.first)
    {
      l_delta_x = -1;
    }
  uint32_t l_new_x = l_other_pos.first + l_delta_x;
  if( l_new_x >= 0 && l_new_x < behaviour_base::m_width) l_other_pos.first = l_new_x;

  int l_delta_y = 0;
  if(l_nearest_pos.second > l_pos.second )
    {
      l_delta_y = 1;
    }
  else if(l_nearest_pos.second < l_pos.second)
    {
      l_delta_y = -1;
    }
  uint32_t l_new_y = l_other_pos.second + l_delta_y;
  if( l_new_y >= 0 && l_new_y < behaviour_base::m_height) l_other_pos.second = l_new_y;

  //  std::cout << "my new pos is " << l_other_pos.first << "\t" << l_other_pos.second << std::endl ;
  set_new_pos(l_other_pos);
}

void social_behaviour::set_class_color(uint32_t p_color)
{
  m_class_colour = p_color;
}

uint32_t social_behaviour::m_class_colour = 0;
//EOF
