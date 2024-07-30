/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:18:46 by maroy             #+#    #+#             */
/*   Updated: 2024/07/29 15:21:36 by maroy            ###   ########.qc       */
/*                                                                            */
/* ************************************************************************** */

template <typename T> void easyfind(T &container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it != container.end()) {
        std::cout << "Element: " << value << " found at position: " << std::distance(container.begin(), it)
                  << std::endl;
    } else {
        throw NotFound();
    }
}
