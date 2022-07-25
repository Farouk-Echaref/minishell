/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:41:39 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/25 20:04:55 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcards.h"

int ft_match(const char *pattern, const char *candidate, int p, int c)
{
	if (pattern[p] == '\0') {
		return candidate[c] == '\0';
	} else if (pattern[p] == '*') {
		for (; candidate[c] != '\0'; c++) {
		if (ft_match(pattern, candidate, p+1, c))
			return 1;
		}
		return ft_match(pattern, candidate, p+1, c);
	} else if (pattern[p] != '?' && pattern[p] != candidate[c]) {
		return 0;
	}  else {
		return ft_match(pattern, candidate, p+1, c+1);
	}
}
