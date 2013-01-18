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
