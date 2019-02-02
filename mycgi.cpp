#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector <string> get_params (string message);
map <string, string> get_key_values(vector <string> params);

int main()
{
	cout << "Content-type: text/html\n\n";
	cout <<"<head>" << endl;
	cout <<"<title>CPP CGI</title>"<<endl;
	cout <<"<meta charset='UTF-8'>"<< endl;
	cout <<"<head>" << endl;
	
  	char* myString = getenv("QUERY_STRING");
	string cppstring = myString;
	
	cout << "<p>The \"QUERY_STRING\" environment variable is " << cppstring << "</p>" << endl;
	
	map <string,string> params = get_key_values(get_params (cppstring));
  	
	cout << "<p>Form input name with value all strings are </p>" << endl;  
    	
	for (auto& x:params) 
    	{
    		cout << "<p>"<<x.first << " : " << x.second << "<p><br/>";
    	}
	//link to return to page with the form 
	cout << "<a href = '../chat/chat_pcgi.php'> return </a>" << endl;
	return 0;
}

vector <string> get_params (string message)
{
	vector <string> params {};
    	while  (message.find('&')!=string::npos)
    	{
        	params.push_back (message.substr(0, message.find('&')));
        	message = message.substr( message.find('&')+1);
    	}
    	params.push_back( message);
    	return params;
}

map <string, string> get_key_values(vector<string> params)
{       
    	map<string,string> mymap = {};
    	for (auto message : params)
    	{
        	mymap.insert( pair <string,string>(message.substr(0, message.find('=')) , message.substr( message.find('=')+1)));
    	}
   	return mymap;
}

