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
#include "simple_gui.h"
#include "random_behaviour.h"
#include "asocial_behaviour.h"
#include "asocial_behaviour2.h"
#include "social_behaviour.h"
#include "super_social_behaviour.h"
#include "erratic_behaviour.h"

#include "environment.h"

#include <iostream>
#include <vector>

#include <signal.h>
#ifdef _WIN32
#include <windows.h>
#endif

bool g_stop;

//------------------------------------------------------------------------------
void sig_handler(int p_sig)
{
  std::cout << "===================> Receive Control-C : execution will stop" << std::endl ;
  g_stop = true;
}


int main(void)
{

#ifndef _WIN32
  //Preparing signal handling to manage stop
  /* Déclaration d'une structure pour la mise en place des gestionnaires */
  struct sigaction l_signal_action;
  
  /* Remplissage de la structure pour la mise en place des gestionnaires */
  /* adresse du gestionnaire */
  l_signal_action.sa_handler=sig_handler;
  // Mise a zero du champ sa_flags theoriquement ignoré
  l_signal_action.sa_flags=0;
  /* On ne bloque pas de signaux spécifiques */
  sigemptyset(&l_signal_action.sa_mask);
  
  /* Mise en place du gestionnaire bidon pour trois signaux */
  sigaction(SIGINT,&l_signal_action,0);
#else
  signal(SIGINT,sig_handler);
#endif

  std::cout << "Hello world" << std::endl ;
  simple_gui l_gui;
  uint32_t l_width = behaviour_base::get_width();
  uint32_t l_height = behaviour_base::get_height();
  l_gui.createWindow(l_width,l_height);

    // initialisation de generateur aleatoire partir de l'heure courante
  srand(time(NULL));
  std::cout << "RAND_MAX = " << RAND_MAX << std::endl ;

  uint32_t l_black = l_gui.getColorCode(0,0,0);
  uint32_t l_red = l_gui.getColorCode(0xff,0,0);
  uint32_t l_green = l_gui.getColorCode(0x0,0xff,0);
  uint32_t l_white = l_gui.getColorCode(0xff,0xff,0xff);
  uint32_t l_yellow = l_gui.getColorCode(0xff,0xff,0x0);
  uint32_t l_violet = l_gui.getColorCode(0xff,0x0,0xff);
  uint32_t l_orange = l_gui.getColorCode(0x0,0xff,0xff);

  random_behaviour::set_class_color(l_white);
  asocial_behaviour::set_class_color(l_red);
  asocial_behaviour2::set_class_color(l_red);
  social_behaviour::set_class_color(l_green);
  super_social_behaviour::set_class_color(l_orange);
  erratic_behaviour::set_class_color(l_yellow);

  std::vector<behaviour_base*> l_groups ;

  environment l_environment(l_width,l_height);

  for(uint32_t l_x = 400 ; l_x < 420 ; ++l_x)
    {
      for(uint32_t l_y = 200 ; l_y < 220 ; ++l_y)
	{
	  l_groups.push_back(new asocial_behaviour2(l_x,l_y));
	  l_environment.occupy_position(std::pair<uint32_t,uint32_t>(l_x,l_y));
	  l_gui.setPixel(l_x,l_y,l_white);
	}
    }
  uint32_t l_index = 0;
  while(l_index < 0)
    {
      //      uint32_t l_x = (int)(l_width * ((float)rand())/RAND_MAX);
      //      uint32_t l_y = (int)(l_height * ((float)rand())/RAND_MAX);      
      //      l_groups.push_back(new random_behaviour(l_x,l_y));
      std::pair<uint32_t,uint32_t> l_pos = l_environment.occupy_random_free_position();
      uint32_t l_x = l_pos.first;
      uint32_t l_y = l_pos.second;
      l_groups.push_back(new random_behaviour(l_x,l_y));
      l_gui.setPixel(l_x,l_y,l_white);
      ++l_index;
    }
 l_index = 0;
  while(l_index < 0)
    {
      //      uint32_t l_x = (int)(l_width * ((float)rand())/RAND_MAX);
      //      uint32_t l_y = (int)(l_height * ((float)rand())/RAND_MAX);      
      //      l_groups.push_back(new random_behaviour(l_x,l_y));
      std::pair<uint32_t,uint32_t> l_pos = l_environment.occupy_random_free_position();
      uint32_t l_x = l_pos.first;
      uint32_t l_y = l_pos.second;
      l_groups.push_back(new asocial_behaviour2(l_x,l_y));
      l_gui.setPixel(l_x,l_y,l_white);
      ++l_index;
    }
 l_index = 0;
  while(l_index < 0)
    {
      //      uint32_t l_x = (int)(l_width * ((float)rand())/RAND_MAX);
      //      uint32_t l_y = (int)(l_height * ((float)rand())/RAND_MAX);      
      //      l_groups.push_back(new random_behaviour(l_x,l_y));
      std::pair<uint32_t,uint32_t> l_pos = l_environment.occupy_random_free_position();
      uint32_t l_x = l_pos.first;
      uint32_t l_y = l_pos.second;
      l_groups.push_back(new social_behaviour(l_x,l_y));
      l_gui.setPixel(l_x,l_y,l_white);
      ++l_index;
    }
 l_index = 0;
  while(l_index < 0)
    {
      //      uint32_t l_x = (int)(l_width * ((float)rand())/RAND_MAX);
      //      uint32_t l_y = (int)(l_height * ((float)rand())/RAND_MAX);      
      //      l_groups.push_back(new random_behaviour(l_x,l_y));
      std::pair<uint32_t,uint32_t> l_pos = l_environment.occupy_random_free_position();
      uint32_t l_x = l_pos.first;
      uint32_t l_y = l_pos.second;
      l_groups.push_back(new super_social_behaviour(l_x,l_y));
      l_gui.setPixel(l_x,l_y,l_white);
      ++l_index;
    }
 l_index = 50;
  while(l_index < 0)
    {
      //      uint32_t l_x = (int)(l_width * ((float)rand())/RAND_MAX);
      //      uint32_t l_y = (int)(l_height * ((float)rand())/RAND_MAX);      
      //      l_groups.push_back(new random_behaviour(l_x,l_y));
      std::pair<uint32_t,uint32_t> l_pos = l_environment.occupy_random_free_position();
      uint32_t l_x = l_pos.first;
      uint32_t l_y = l_pos.second;
      l_groups.push_back(new erratic_behaviour(l_x,l_y));
      l_gui.setPixel(l_x,l_y,l_white);
      ++l_index;
    }
  l_gui.refresh();

  while(!g_stop)
    {
      std::vector<behaviour_base*>::iterator l_iter = l_groups.begin();
      std::vector<behaviour_base*>::iterator l_iter_end = l_groups.end();

      // Deleting from screen
      while(l_iter != l_iter_end)
	{
	  l_gui.setPixel((*l_iter)->get_x(),(*l_iter)->get_y(),l_black);
	  ++l_iter;
	}

      // Choosing new position
      for(uint32_t l_index = 0 ; l_index < l_groups.size() ; ++l_index)
	{
	  uint32_t l_random_index = (int)((l_groups.size() - l_index) * ((float)rand())/RAND_MAX);
	  bool l_ok = false;

	  l_groups[l_random_index]->choose_next_pos(l_groups,l_environment);
	  l_ok = l_environment.is_position_free(l_groups[l_random_index]->get_next_pos());
	  if(l_ok)
	    {
	      l_environment.free_position(std::pair<uint32_t,uint32_t>(l_groups[l_random_index]->get_x(),l_groups[l_random_index]->get_y()));
	      l_groups[l_random_index]->move();
	      l_environment.occupy_position(std::pair<uint32_t,uint32_t>(l_groups[l_random_index]->get_x(),l_groups[l_random_index]->get_y()));
	    }
	  std::swap(l_groups[l_index],l_groups[l_random_index]);
	}
 
      // redisplaying
      l_iter = l_groups.begin();
      while(l_iter != l_iter_end)
	{
	  l_gui.setPixel((*l_iter)->get_x(),(*l_iter)->get_y(),(*l_iter)->get_color());
	  ++l_iter;
	}
      l_gui.refresh();


      //      uint32_t l_color_cmp = (int)(255 * ((float)rand())/RAND_MAX);
      //      uint32_t l_color = l_gui.getColorCode(l_color_cmp,l_color_cmp,l_color_cmp);
      //      int l_delta_x = (int)(3 * ((float)rand())/RAND_MAX) -1 ;
      //      int l_delta_y = (int)(3 * ((float)rand())/RAND_MAX) -1 ;
      //      uint32_t l_new_x = l_x + l_delta_x;
      //      uint32_t l_new_y = l_y + l_delta_y;
      //      l_gui.setPixel(l_x,l_y,l_black);
      //      if( l_new_x >= 0 && l_new_x < l_width) l_x = l_new_x;
      //      if( l_new_y >= 0 && l_new_y < l_height) l_y = l_new_y;
      //      l_gui.setPixel(l_x,l_y,l_color);
    }

}
