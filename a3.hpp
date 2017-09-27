/***
 *  File: a3.hpp
 *  Author: Frederick Ho fho2
 */

#ifndef A3_HPP
#define A3_HPP

// MAKE SURE TO UPDATE YOUR INFORMATION IN THE HEADER OF THIS FILE
// IMPLEMENT MISSING FUNCTIONALITY OF key_value_sequences IN THIS FILE
// YOU ARE NOT ALLOWED TO INCLUDE ANY OTHER HEADERS THAN
// <algorithm>, <list>, <vector>
// YOU CAN CHANGE/EDIT ANY CODE IN THIS FILE AS LONG AS SEMANTICS IS UNCHANGED
// AND MATCHES SPECIFICATION PROVIDED IN THE ASSIGNMENT TEXT

#include <algorithm>
#include <list>
#include <vector>

class key_value_object{
public:
  int key;
  std::vector<int> values;
};
class key_value_sequences
{
public:
    // YOU SHOULD USE C++ CONTAINERS TO AVOID RAW POINTERS
    // IF YOU DECIDE TO USE POINTERS, MAKE SURE THAT YOU MANAGE MEMORY PROPERLY
    // IMPLEMENT ME: SHOULD RETURN SIZE OF A SEQUENCEFOR GIVEN KEY
    // IF NO SEQUENCE EXISTS FOR A GIVEN KEY RETURN -1
  key_value_sequences()
  {
    myarray = std::vector<std::vector<key_value_object> > (300149);
  }
  int size(int key) const
  {
    //  std::cout << that.values.size() << std::endl;
    int tmp = key%300149; // gives which index to put the vectorofsequences in
    //  std::abs(tmp);
    if(tmp < 0)
      {
	tmp = tmp * -1;
      }
    for(int i = 0; i<myarray[tmp].size(); ++i)
       {
	 if(myarray[tmp].at(i).key == key)
	   {
	     return myarray[tmp].at(i).values.size();
	     // std::cout << myarray[tmp].at(i).values.size();
	   } 
       }
  return -1;
}
  // IMPLEMENT ME: SHOULD RETURN POINTER TO A SEQUENCE FOR GIVEN KEY
    // IF NO SEQUENCE EXISTS FOR A GIVEN KEY RETURN nullptr
    const int* data(int key) const
  {
    int tmp = key%300149; // gives which index to put the vectorofsequences in
    if(tmp<0)
      {
	tmp = tmp * -1;
      }
     for(int i = 0; i<myarray[tmp].size(); ++i)
       {
	 if(myarray[tmp].at(i).key == key)
	   {
	     return myarray[tmp].at(i).values.data();
	   } 
       }
    return nullptr;
  }

    // IMPLEMENT ME: INSERT VALUE INTO A SEQUENCE IDENTIFIED BY GIVEN KEY
   
  void insert(int key, int value)
  {
    int tmp = key%300149;
    if(myarray[tmp].empty())
       {
	 key_value_object that;
	 myarray[tmp] = std::vector<key_value_object> (0);
	 that.key = key;
	 that.values.push_back(value);
	 myarray[tmp].push_back(that);
       }else
	  {
	    for(int i = 0; i<myarray[tmp].size(); ++i)
	      {
		if(myarray[tmp].at(i).key == key)
		  {
		    myarray[tmp].at(i).values.push_back(value);
		  }else
		  {
		    key_value_object that;
		    that.key = key;
		    that.values.push_back(value);
		    myarray[tmp].push_back(that);
		  }
	      }
	  }
       
  
}
    //  bool keyexists = false;
    // int tmp = key%300149;
    //  std::abs(tmp);
    // if(tmp < 0)
    // {
    //	tmp = tmp * -1;
    //}
    // if(myarray[tmp].empty()) 
    //{
    //  myarray[tmp] = std::vector<key_value_object> (0);
    //	key_value_object that;
    //	that.key = key;
    //	that.values.push_back(value);
    //	myarray[tmp].push_back(that);
    //	}else if(!myarray[tmp].empty())
    //{
    //	for(int i = 0; i<myarray[tmp].size(); ++i)
    //	  {
    //	  
    //	  if(myarray[tmp].at(i).key == key)
    //	    {
    //	      myarray[tmp].at(i).values.push_back(value);
    //	      break;
    //	    }else if (keyexists == false)
    //	    {
    //	      key_value_object that;
    //	      that.key = key;
    //	      that.values.push_back(value);
    //	      myarray[tmp].push_back(that);
    //	    }
    //	}
    //
    // }
   

  
private:
  std::vector<std::vector<key_value_object> > myarray;
  std::vector<key_value_object> vectorholdingobject;
  
}; // class key_value_sequences

#endif // A3_HPP
