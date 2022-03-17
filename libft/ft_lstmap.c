#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*next;
	t_list	*temp;

	temp = ft_lstnew(lst->content);
	lst = lst->next;
	while (lst)
	{
		next = ft_lstnew(f(lst->content));
		if (!next)
		{
			ft_lstclear(&temp, del);
			return (NULL);
		}
		ft_lstadd_back(&temp, next);
		lst = lst->next;
	}
	return (temp);
}
