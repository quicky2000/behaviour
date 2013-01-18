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
