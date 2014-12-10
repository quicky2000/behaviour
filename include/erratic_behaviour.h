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
