/*
 * alerters.c
 *
 *  Created on: May 17, 2022
 *      Author: ACL4KOR
 */

#include "alerters.h"
#include "stats.h"

void emailAlerter()
{
    emailAlertCallCount += 1;
}

void ledAlerter()
{
    ledAlertCallCount += 1;
}
