//
//  stdtostring.h
//  GFProject
//
//  Created by liumin on 5/20/19.
//

#ifndef stdtostring_h
#define stdtostring_h

#include <string>
#include <sstream>

using namespace std;
namespace std
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

#endif /* stdtostring_h */
