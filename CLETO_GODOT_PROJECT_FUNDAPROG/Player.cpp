#include "Player.h"

//Libraries
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/project_settings.hpp>
#include <godot_cpp/classes/input.hpp>
//#include <godot_cpp/classes/input_event_mouse.hpp>
//#include <godot_cpp/classes/input_event_mouse_motion.hpp>
//#include <godot_cpp/classes/physics_body3d.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/remote_transform3d.hpp>
#include <godot_cpp/variant/basis.hpp>
#include <godot_cpp/classes/scene_tree.hpp>
#include <godot_cpp/classes/engine.hpp>



using namespace godot;

void Player:: _bind_methods()
{
  
//Here is the functions that will appear in GDScript

//Methods of class Player besides setters and getters
  //Player death
  ClassDB::bind_method(D_METHOD("player_death"), &Player::player_death);
  //Debug
  ClassDB::bind_method(D_METHOD("debug"), &Player::debug);
  //Recieve tokens
  ClassDB::bind_method(D_METHOD("recieve_tokens", "amount_of_tokens"), &Player::recieve_tokens);
//Setters and Getters
  //Speed
  ClassDB::bind_method(D_METHOD("get_speed"), &Player::get_speed);
  ClassDB::bind_method(D_METHOD("set_speed", "speed"), &Player::set_speed);
  //Mouse Sensitivity
  ClassDB::bind_method(D_METHOD("get_mouse_sensitivity"), &Player::get_mouse_sensitivity);
  ClassDB::bind_method(D_METHOD("set_mouse_sensitivity", "mouse_sensitivity"), &Player::set_mouse_sensitivity);
  //Gravity
  ClassDB::bind_method(D_METHOD("get_gravity"), &Player::get_gravity);
  ClassDB::bind_method(D_METHOD("set_gravity", "p_gravity"), &Player::set_gravity);
  //Health
  ClassDB::bind_method(D_METHOD("get_health"), &Player::get_health);
  ClassDB::bind_method(D_METHOD("set_health", "health"), &Player::set_health);
  //Amount Of Tokens
  ClassDB::bind_method(D_METHOD("get_amount_of_tokens"), &Player::get_amount_of_tokens);
  ClassDB::bind_method(D_METHOD("set_amount_of_tokens", "amount of tokens"), &Player::set_amount_of_tokens);
  //Name
  ClassDB::bind_method(D_METHOD("get_name"), &Player::get_name);
  ClassDB::bind_method(D_METHOD("set_name", "name"), &Player::set_name);
  //Recieve Tokens
  ClassDB::bind_method(D_METHOD("recieve_tokens"), &Player::recieve_tokens);


  //TestFunctions
  ClassDB::bind_method(D_METHOD("get_amountTacos"), &Player::get_amountTacos);
  ClassDB::bind_method(D_METHOD("set_amountTacos", "tacos"), &Player::set_amountTacos);
  ClassDB::bind_method(D_METHOD("hellofuckers"), &Player::hellofuckers);
  
//Adding to the editor
  //Speed
  ClassDB::add_property("Player", PropertyInfo(Variant::FLOAT, "speed"), "set_speed", "get_speed");
  //Mouse Sensitivity
  ClassDB::add_property("Player", PropertyInfo(Variant::FLOAT, "mouse_sensitivity"), "set_mouse_sensitivity", "get_mouse_sensitivity");
  //Gravity
  ClassDB::add_property("Player", PropertyInfo(Variant::FLOAT, "gravity" ), "set_gravity", "get_gravity");
  //Health
  ClassDB::add_property("Player", PropertyInfo(Variant::FLOAT, "health"), "set_health", "get_health");
  //Name
  ClassDB::add_property("Player", PropertyInfo(Variant::STRING, "name"), "set_name", "get_name");
  //Tokens
  ClassDB::add_property("Player", PropertyInfo(Variant::INT, "amount_of_tokens"), "set_amount_of_tokens", "get_amount_of_tokens");
  //TestFunctions
  ClassDB::add_property("Player", PropertyInfo(Variant::INT, "amountTacos"), "set_amountTacos", "get_amountTacos");

  //SIGNALS
  ADD_SIGNAL(MethodInfo("Tokens_Acquired", PropertyInfo(Variant::INT, "tokens")));


}
  
Player::Player()
{
  //ProjectSettings& ProjectSettingsSingleton = *ProjectSettings::get_singleton();
  
  Input& input = *Input::get_singleton();
  ProjectSettings& PS = *ProjectSettings::get_singleton();
  gravity = PS.get_setting("physics/3d/default_gravity");
  speed = 5;
  jump_velocity = 5.0;
  mouse_sensitivity = 1.0;
  health = 1.0f;
  amount_of_tokens = 0;
  name = "Jeff";
  //isDead = false;

  //TestAtt
  amountTacos = 70;
}

Player::~Player()
{
  //Add cleanup here
}
//Methods other than setters and getters of class Player

//This method from class Player filters names
//If name is forbidden it will go to the default name
//if not it will then proceed
String Player::name_filter(String name){
  
  String forbidden_names[10] = {"Fuck", "Shit", "Retard", "Bitch"};
  for (int i = 0; i < 10; i++)
  {
    if (name == forbidden_names[i].to_lower() || name == forbidden_names[i])
    {
      name = "Jeff";
      UtilityFunctions::print("Error: Invalid Input > Forbidden name");
      UtilityFunctions::print("Please choose another name");
    }
    
  }
  return name;
}

//This function limits player health
float Player::limit_health(float health){
  if (health > 100 || health < 0)
  {
    UtilityFunctions::print("Error: Invalid Input must be in range 0 to 100");
    UtilityFunctions::print("Returning to default");
    health = 100.0f;
  }
  return health;
}

//this method limits speed
double Player::limit_speed(double speed)
{
  if(speed < 0 || speed > 5)
  {
    UtilityFunctions::print("Error: Invalid Input must be in range 0 to 5");
    UtilityFunctions::print("Returning to default");
    speed = 5;
  }
  return speed;
}

//this method limits amount of tokens
int Player::limit_amount_of_tokens(int amount_of_tokens)
{
  if(amount_of_tokens < 0 || amount_of_tokens > 5)
  {
    UtilityFunctions::print("Error: Invalid Input must be in range 0 to 5");
    UtilityFunctions::print("Returning to default");
    amount_of_tokens = 0;
  }
  return amount_of_tokens;
}

//player death
void Player::player_death()
{
  if (health == 0)
  {
    get_tree()->change_scene_to_file("res://overpower_level/YOUDIED.tscn");
  }
  
}

//Recieve tokens
void Player::recieve_tokens(){
  
  ++amount_of_tokens;
}

//Debug
void Player::debug()
{
  //UtilityFunctions::print(recieve_tokens(limit_amount_of_tokens(get_amount_of_tokens())));
  get_tree()->quit();
}
//Setters and Getters for Player below

//Gravity
void Player::set_gravity(const double gravity)
{
  this->gravity = gravity;
}

double Player::get_gravity() const {
  return gravity;
}

//Speed
void Player::set_speed(const double speed)
{
  this->speed = limit_speed(speed);
}

double Player::get_speed() const {
  return speed;
}

//Mouse Sensitivity
void Player::set_mouse_sensitivity(const double mouse_sensitivity){
  this->mouse_sensitivity = mouse_sensitivity;
}

double Player::get_mouse_sensitivity() const {
  return mouse_sensitivity;
}

//Health
void Player::set_health(const float health){
  this -> health = limit_health(health);
}

float Player::get_health() const {
  return health;
}

//Amount of Tokens
void Player::set_amount_of_tokens(const int amount_of_tokens)
{
  this -> amount_of_tokens = limit_amount_of_tokens(amount_of_tokens);
}

int Player::get_amount_of_tokens() const{
  return amount_of_tokens;
}

//Name (String Manipulation)
void Player::set_name(const String name)
{
  this->name = name_filter(name);
}

String Player::get_name() const {
  return name;
}

//TestFunctions
int Player::get_amountTacos() const{
  return amountTacos;
}

void Player::set_amountTacos(const int tacos){
  this -> amountTacos = tacos;
}

void Player::hellofuckers(){
  UtilityFunctions::print("Hello " + get_name());
}



//BELLA CIAO

