/*    This file is part of behaviour
      Copyright (C) 2014  Julien Thevenon ( julien_thevenon at yahoo.fr )

      This program is free software: you can redistribute it and/or modify
      it under the terms of the GNU General Public License as published by
      the Free Software Foundation, either version 3 of the License, or
      (at your option) any later version.

      This program is distributed in the hope that it will be useful,
      but WITHOUT ANY WARRANTY; without even the implied warranty of
      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
      GNU General Public License for more details.

      You should have received a copy of the GNU General Public License
      along with this program.  If not, see <http://www.gnu.org/licenses/>
*/
#include "asocial_behaviour.h"
#include <stdlib.h>
#include <math.h>
#include <iostream>

asocial_behaviour::asocial_behaviour(uint32_t l_x, uint32_t l_y):
  behaviour_base(l_x,l_y,m_class_colour)
{
}

void asocial_behaviour::choose_next_pos(const std::vector<behaviour_base *> & p_others,environment & p_environment)
{
  std::pair<uint32_t,uint32_t> l_pos = get_pos();
  // std::cout << "My pos = " << l_pos.first << "\t" << l_pos.second << std::endl ;
  uint32_t l_dist_min = UINT32_MAX;
  std::pair<uint32_t,uint32_t> l_nearest_pos,l_other_pos;
  std::vector<behaviour_base *>::const_iterator l_iter = p_others.begin();
  std::vector<behaviour_base *>::const_iterator l_iter_end = p_others.end();
  while(l_iter != l_iter_end)
    {
      l_other_pos = (*l_iter)->get_pos();
      uint32_t l_dist = pow(((int32_t)l_other_pos.first) - ((int32_t)l_pos.first),2) + pow(((int32_t)l_other_pos.second) - ((int32_t)l_pos.second),2);
      if(l_dist && l_dist < l_dist_min)
	{
	  l_dist_min = l_dist;
	  l_nearest_pos = l_other_pos;
	}
      ++l_iter;
    }
  //  std::cout << "nearest neighbour is " << l_nearest_pos.first << "\t" << l_nearest_pos.second << std::endl ;
  l_other_pos = l_pos;

  int l_delta_x = 0;
  if(l_nearest_pos.first > l_pos.first)
    {
      l_delta_x = -1;
    }
  else if(l_nearest_pos.first < l_pos.first)
    {
      l_delta_x = 1;
    }
  else
    {
      l_delta_x = 2 * ((int) (2 * ((float)rand())/RAND_MAX)) - 1 ;
    }
  uint32_t l_new_x = l_other_pos.first + l_delta_x;
  if( l_new_x >= 0 && l_new_x < behaviour_base::m_width) l_other_pos.first = l_new_x;

  int l_delta_y = 0;
  if(l_nearest_pos.second > l_pos.second)
    {
      l_delta_y = -1;
    }
  else if(l_nearest_pos.second < l_pos.second)
    {
      l_delta_y = 1;
    }
  else
    {
      l_delta_y = 2 * ((int) (2 * ((float)rand())/RAND_MAX)) - 1 ;
    }
  uint32_t l_new_y = l_other_pos.second + l_delta_y;
  if( l_new_y >= 0 && l_new_y < behaviour_base::m_height) l_other_pos.second = l_new_y;

  //  std::cout << "my new pos is " << l_other_pos.first << "\t" << l_other_pos.second << std::endl ;
  set_new_pos(l_other_pos);
}

void asocial_behaviour::set_class_color(uint32_t p_color)
{
  m_class_colour = p_color;
}

uint32_t asocial_behaviour::m_class_colour = 0;
//EOF
