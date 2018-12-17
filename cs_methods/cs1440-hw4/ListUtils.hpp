/*                                                                                                                                         
 * WARNING!
 *
 * You should not edit this file
 */

#pragma once

#include <string>

#include "Employment.hpp"

Employment* build_empl_list(std::string filename);

void append_lists(Employment* head, Employment* tail);

int list_length(Employment *emp);

void print_every_empl(Employment *emp);

void cleanup_list(Employment * emp);
