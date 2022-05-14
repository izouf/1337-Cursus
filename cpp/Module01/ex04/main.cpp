/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <izouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:16:07 by izouf             #+#    #+#             */
/*   Updated: 2022/05/14 13:24:36 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string ft_replace(std::string content, const std::string s1, const std::string s2)
{
    size_t  pos = 0;

    pos = content.find(s1);
    while (pos != std::string::npos)
    {
        content.erase(pos,s1.length());
        content.insert(pos, s2);
        pos = content.find(s1, pos + s2.length());
    }
    return (content);
}

int main(int ac, char *av[])
{
    std::ifstream           r;
    std::ofstream           w;
    std::string             newFile ;
    std::string             content;

    if (ac != 4 || !av[2][0])
    {
        std::cout << "Wrong Parameters" << std::endl;
        exit(1);
    }
    
    r.open(av[1]);
    if (r.is_open())
    {
        w.open((std::string) av[1] + ".replace", std::ios::out | std::ios::trunc);
        if (w.is_open() )
        {
            while(std::getline(r, content))
            {
                content = ft_replace(content, av[2], av[3]);
                w << content;
                if (r.peek() != EOF)
                w << std::endl;
            }
            w.close();
        }
        else
        {
            std::cout << "Outfile Error " << std::endl;
            exit(1);
        }
    }
    return (0);
}