#include "asocial_behaviour2.h"
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include "environment.h"
asocial_behaviour2::asocial_behaviour2(uint32_t l_x, uint32_t l_y):
  behaviour_base(l_x,l_y,m_class_colour)
{
}

void asocial_behaviour2::choose_next_pos(const std::vector<behaviour_base *> & p_others,environment & p_environment)
{
  std::pair<uint32_t,uint32_t> l_pos = get_pos();
  std::pair<uint32_t,uint32_t> l_nearest_pos = l_pos;
  uint32_t l_dist_max = 0;
  //  std::cout << "My pos = " << l_pos.first << "\t" << l_pos.second << std::endl ;
  for(int32_t l_delta_x = -1; l_delta_x < 2 ; ++l_delta_x)
    {
      for(int32_t l_delta_y = -1; l_delta_y < 2 ; ++l_delta_y)
	{
	  int32_t l_new_x = (int32_t)l_pos.first + l_delta_x;
	  int32_t l_new_y = (int32_t)l_pos.second + l_delta_y;
	  std::pair<uint32_t,uint32_t> l_new_pos = std::pair<uint32_t,uint32_t>(l_new_x, l_new_y);
	  if( l_new_x >= 0 && l_new_x < (int32_t)behaviour_base::m_width && l_new_y >= 0 && l_new_y < (int32_t)behaviour_base::m_height && p_environment.is_position_free(std::pair<uint32_t,uint32_t>(l_new_x,l_new_y)))
	    {
	      //	         std::cout << "Check pos " << l_new_x << "\t" << l_new_y << std::endl ;
	      std::vector<behaviour_base *>::const_iterator l_iter = p_others.begin();
	      std::vector<behaviour_base *>::const_iterator l_iter_end = p_others.end();
	      uint32_t l_dist_min = UINT32_MAX;
	      while(l_iter != l_iter_end)
		{
		  std::pair<uint32_t,uint32_t> l_other_pos = (*l_iter)->get_pos();
		  if(l_other_pos.first != l_pos.first || l_other_pos.second != l_pos.second)
		    {
		      uint32_t l_dist = pow(((int32_t)l_other_pos.first) - ((int32_t)l_new_pos.first),2) + pow(((int32_t)l_other_pos.second) - ((int32_t)l_new_pos.second),2);
		      //		      std::cout << "dist = " << l_dist << "\tdist_min" << l_dist_min << std::endl ;
		      if(l_dist && l_dist < l_dist_min)
			{
			  l_dist_min = l_dist;
			}
		    }
		  ++l_iter;
		}
	      //	      std::cout << "dist_min = " << l_dist_min << "\tdist_max" << l_dist_max << std::endl ;
	      if(l_dist_min != UINT32_MAX && l_dist_min > l_dist_max)
		{
		  l_dist_max = l_dist_min;
		  l_nearest_pos = l_new_pos;
		  //		  std::cout << "Candidate pos is " << l_nearest_pos.first << "\t" << l_nearest_pos.second << std::endl ;
		}
	    }
	}
    }

  //  std::cout << "New pos is " << l_nearest_pos.first << "\t" << l_nearest_pos.second << std::endl ;
  set_new_pos(l_nearest_pos);
}

void asocial_behaviour2::set_class_color(uint32_t p_color)
{
  m_class_colour = p_color;
}

uint32_t asocial_behaviour2::m_class_colour = 0;
//EOF
