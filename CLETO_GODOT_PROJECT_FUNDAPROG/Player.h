#ifndef PLAYER_H
#define PLAYER_H

#include <godot_cpp/classes/character_body3d.hpp>

namespace godot {

  class Player : public CharacterBody3D {
    GDCLASS(Player, CharacterBody3D)
    
    private:
      double gravity;
      double speed;
      double jump_velocity;
      double mouse_sensitivity; //Do I need this?
      float health;
      int amount_of_tokens;
      
      
      //Test attr.
      int amountTacos;
      
    
    protected:
      static void _bind_methods();
      
    public:
      Player();
      ~Player();
      
    //Setters and Getters of player
      //Gravity
      void set_gravity(const double gravity);
      double get_gravity() const;
      //Speed
      void set_speed(const double speed);
      double get_speed() const;
      //Jump velocity
      void set_jump_velocity(const double jump_velocity);
      double get_jump_velocity() const;
      //Mouse velocity
      void set_mouse_sensitivity(const double mouse_sensitivity);
      double get_mouse_sensitivity() const;
      //Health
      void set_health(const float health);
      float get_health() const;
      //Amount of tokens
      void set_amount_of_tokens(const int amount_of_tokens);
      int get_amount_of_tokens() const;
      
      
      //TEST FUNCTION BELOW
      void hellofuckers();
      void set_amountTacos(const int tacos);
      int get_amountTacos() const;
      
  }; 
}

#endif
