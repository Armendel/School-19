/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaini <asaini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:51:10 by asaini            #+#    #+#             */
/*   Updated: 2023/06/12 18:39:55 by asaini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*curr;
	int		count;

	if (!lst)
		return (0);
	count = 1;
	curr = lst;
	while (curr->next)
	{
		count++;
		curr = curr->next;
	}
	return (count);
}
