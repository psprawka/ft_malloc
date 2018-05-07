/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_rotations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 13:38:57 by psprawka          #+#    #+#             */
/*   Updated: 2018/05/01 13:39:00 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

/*
**	Description of functions rotate_left and rotate_right avaliable here ↓
**	https://en.wikipedia.org/wiki/Red%E2%80%93black_tree
*/

void	rotate_left(t_tag *tag)
{
	t_tag *new_head;

	new_head = tag->right;
	tag->right = new_head->left;
	if (new_head->left)
		new_head->left->parent = tag;
	new_head->left = tag;
	new_head->parent = tag->parent;
	tag->parent = new_head;
	if (new_head->parent && new_head->parent->left == tag)
		new_head->parent->left = new_head;
	if (new_head->parent && new_head->parent->right == tag)
		new_head->parent->right = new_head;
//	if (!new_head->parent)
//		g_tags_tree = new_head;
}

void	rotate_right(t_tag *tag)
{
	t_tag *new_head;

	new_head = tag->left;
	tag->left = new_head->right;
	if (new_head->right)
		new_head->right->parent = tag;
	new_head->right = tag;
	new_head->parent = tag->parent;
	tag->parent = new_head;
	if (new_head->parent && new_head->parent->left == tag)
		new_head->parent->left = new_head;
	if (new_head->parent && new_head->parent->right == tag)
		new_head->parent->right = new_head;
//	if (!new_head->parent)
//		g_tags_tree = new_head;
}

