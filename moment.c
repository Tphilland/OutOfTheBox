/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moment.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphillan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 06:09:47 by tphillan          #+#    #+#             */
/*   Updated: 2019/11/21 06:10:17 by tphillan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

/*This program takes in seconds as input, and returns them as either seconds(if the input is less than a minute),
minutes, hours, days or months*/

char	*dura(unsigned int duration, int x, char *dur, char *str)
{
	int d;
	int i;
	int j;

	j = 0;
	duration = duration/x;
	d = (int)duration;
	if (duration >= 10)
	{
		dur = (char *)malloc(14*sizeof(char));
		duration = duration/10 + '0';
		d = d%10 + '0';
		dur[0] = duration;
		dur[1] = d;
		dur[2] = ' ';
		i = 3;
		while (str[j])
			dur[i++] = str[j++];
		dur[i] = '\0';
	}
	else
	{
		dur = (char *)malloc(sizeof(char) *14);
		dur[0] = d + '0';
		dur[1] = ' ';
		i = 2;
		while (str[j])
			dur[i++] = str[j++];
		dur[i] = '\0';
	}
	return (dur);
}

char	*moment(unsigned int duration)
{
	char	*dur;
	if (duration >= 0 && duration < 60)
	{
		char sec[11] = "second ago\0";
		char secs[12] = "seconds ago\0";
		if (duration == 1)
			dur = dura(duration, 1, dur, sec);
		else
			dur = dura(duration, 1, dur, secs);
	}
	else if (duration >= 60 && duration < 3600)
	{
		char min[11] = "minute ago\0";
		char mins[12] = "minutes ago\0";
		if (duration/60 == 1)
			dur = dura(duration, 60,dur, min);
		else
			dur = dura(duration,60,dur,mins);
	}
	else if (duration >= 3600 && duration < 86400)
	{
		char hr[9] = "hour ago\0";
		char hrs[10] = "hours ago\0";
		if (duration/3600 == 1)
			dur = dura(duration, 3600,dur, hr);
		else
			dur = dura(duration,3600,dur,hrs);
	}
	else if (duration >= 86400 && duration < 2592000)
	{
		char day[8] = "day ago\0";
		char days[9] = "days ago\0";
		if (duration/86400 == 1)
			dur = dura(duration, 86400,dur, day);
		else
			dur = dura(duration,86400,dur, days);
	}
	else if (duration >= 2592000)
	{
		char mon[10] = "month ago\0";
		char mons[11] = "months ago\0";
		if (duration/2592000 == 1)
			dur = dura(duration, 2592000,dur, mon);
		else
			dur = dura(duration,2592000,dur, mons);
	}
	else
			dur = "NULL";
		return (dur);
	}

	int main(void)
	{
		char *dur;
		unsigned int sec;

		scanf("%d", &sec);
		dur = moment(sec);
		printf ("%s\n", dur);
		free(dur);
		return (0);
	}
