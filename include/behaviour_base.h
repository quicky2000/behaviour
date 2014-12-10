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
#ifndef _BEHAVIOUR_BASE_H_
#define _BEHAVIOUR_BASE_H_

#include <stdint.h>
#include <utility>
#include <vector>

class environment;

class behaviour_base
{
public:
  behaviour_base(uint32_t l_x, uint32_t l_y,uint32_t p_color);
  uint32_t get_x(void)const;
  uint32_t get_y(void)const;
  uint32_t get_color(void)const;
  const std::pair<uint32_t,uint32_t> &  get_pos(void)const;
  void move(void);
  virtual void choose_next_pos(const std::vector<behaviour_base *> & p_others,environment & p_environment)=0; 
  const std::pair<uint32_t,uint32_t> & get_next_pos(void)const;
  inline static uint32_t get_width(void){return m_width;};
  inline static uint32_t get_height(void){return m_height;};
 protected:
  void set_new_pos(const std::pair<uint32_t,uint32_t> & p_new_pos);
  static const uint32_t m_width;
  static const uint32_t m_height;
private:
  std::pair<uint32_t,uint32_t> m_pos;
  std::pair<uint32_t,uint32_t> m_next_pos;
  uint32_t m_color;
};

#endif /* _BEHAVIOUR_BASE_H_ */
