#include <dirent.h>

#include "DirToList.hpp"
#include "ListUtils.hpp"

/*
 * DirToList()
 *
 * Given the name of a directory, create and return one, big, linked-list
 * containing all of the data from all of the files
 */
Employment* DirToList(std::string dir) {
	DIR *dp;

	// Open the directory containing the data
    // If that fails, return NULL
	dp = opendir(dir.c_str());
	if (dp == NULL) {
		perror("opendir");
		return (Employment *)NULL;
	}

    // `base` is the name of the directory containing our files plus a '/'
	std::string base(dir);
	base += "/";

    // This variable points to the head of the list. It must *always* point to
    // the head of the list.
    //
    // You'll need to make a temporary variable within this loop to follow the
    // `tail` of the list as you construct it.
	Employment* head = (Employment *)NULL;

	struct dirent *entry;
	
	while ((entry = readdir(dp))) 
	{
		if (entry->d_name[0] != '.') 
		{
			std::string filename = base + (std::string) entry->d_name;
			//#warning "TODO: Create your linked-list with build_empl_list() and append_lists()"
			if(head == NULL)
			{
				head = build_empl_list(filename);
			}
			else
			{
				append_lists(head, build_empl_list(filename));	
			}
		}
	}
	closedir(dp);
	return head;
}
