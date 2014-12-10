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
#ifndef _ENVIRONMENT_H_
#define _ENVIRONMENT_H_

#include <set>
#include <inttypes.h>
#include <assert.h>

class environment
{
 public:
  inline environment(const uint32_t & p_width,const uint32_t & p_height);
  inline const std::pair<uint32_t,uint32_t> occupy_random_free_position(void);
  inline void free_position(const std::pair<uint32_t,uint32_t> & p_pos);
  inline bool is_position_free(const std::pair<uint32_t,uint32_t> & p_pos)const;
  inline void occupy_position(const std::pair<uint32_t,uint32_t> & p_pos);
 private:
  std::set<std::pair<uint32_t,uint32_t> > m_busy_positions;
  const uint32_t m_width;
  const uint32_t m_height;
};

//------------------------------------------------------------------------------
environment::environment(const uint32_t & p_width,const uint32_t & p_height):
  m_width(p_width),
  m_height(p_height)
{
}

//------------------------------------------------------------------------------
const std::pair<uint32_t,uint32_t> environment::occupy_random_free_position(void)
{
  uint32_t l_x;
  uint32_t l_y;
  do
    {
      l_x = (int)(m_width * ((float)rand())/RAND_MAX);
      l_y = (int)(m_height * ((float)rand())/RAND_MAX);
    } while(m_busy_positions.find(std::pair<uint32_t,uint32_t>(l_x,l_y)) != m_busy_positions.end());
  m_busy_positions.insert(std::pair<uint32_t,uint32_t>(l_x,l_y));
  return std::pair<uint32_t,uint32_t>(l_x,l_y);
}

//------------------------------------------------------------------------------
void environment::free_position(const std::pair<uint32_t,uint32_t> & p_pos)
{
  std::set<std::pair<uint32_t,uint32_t> >::iterator l_iter = m_busy_positions.find(p_pos);
  assert(l_iter != m_busy_positions.end());
  m_busy_positions.erase(l_iter);
}

//------------------------------------------------------------------------------
void environment::occupy_position(const std::pair<uint32_t,uint32_t> & p_pos)
{
  std::set<std::pair<uint32_t,uint32_t> >::iterator l_iter = m_busy_positions.find(p_pos);
  assert(l_iter == m_busy_positions.end());
  m_busy_positions.insert(p_pos);
}

//------------------------------------------------------------------------------
bool environment::is_position_free(const std::pair<uint32_t,uint32_t> & p_pos)const
{
  return m_busy_positions.find(p_pos) == m_busy_positions.end();
}

#endif // _ENVIRONMENT_H_
//EOF
