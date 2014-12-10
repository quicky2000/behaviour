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
#include "behaviour_base.h"

//------------------------------------------------------------------------------
behaviour_base::behaviour_base(uint32_t l_x, uint32_t l_y,uint32_t p_color):
  m_pos(l_x,l_y),
  m_next_pos(0,0),
  m_color(p_color)
{
}

//------------------------------------------------------------------------------
uint32_t behaviour_base::get_x(void)const
{
  return m_pos.first;
}

//------------------------------------------------------------------------------
uint32_t behaviour_base::get_y(void)const
{
  return m_pos.second;
}

uint32_t behaviour_base::get_color(void)const
{
  return m_color;
}

//------------------------------------------------------------------------------
const std::pair<uint32_t,uint32_t> &  behaviour_base::get_pos(void)const
{
  return m_pos;
}

//------------------------------------------------------------------------------
const std::pair<uint32_t,uint32_t> &  behaviour_base::get_next_pos(void)const
{
  return m_next_pos;
}

//------------------------------------------------------------------------------
void behaviour_base::move(void)
{
  m_pos = m_next_pos;
}

//------------------------------------------------------------------------------
void behaviour_base::set_new_pos(const std::pair<uint32_t,uint32_t> & p_new_pos)
{
  m_next_pos = p_new_pos;
}

const uint32_t behaviour_base::m_width = 800;
const uint32_t behaviour_base::m_height = 400;


//EOF
