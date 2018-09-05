/**
 * This file is part of Hercules.
 * http://herc.ws - http://github.com/HerculesWS/Hercules
 *
 * Copyright (C) 2012-2018  Hercules Dev Team
 * Copyright (C)  Athena Dev Teams
 *
 * Hercules is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef MAP_DUEL_H
#define MAP_DUEL_H

#include "common/hercules.h"

struct map_session_data;

struct duel {
	int members_count;
	int invites_count;
	int max_players_limit;
};

#define MAX_DUEL 1024

/*=====================================
* Interface : duel.h
* Generated by HerculesInterfaceMaker
* created by Susu
*-------------------------------------*/
struct duel_interface {

	/* vars */
	struct duel list[MAX_DUEL];
	int count;

	/* funcs */
	//Duel functions // [LuzZza]
	int (*create) (struct map_session_data* sd, const unsigned int maxpl);
	void (*invite) (const unsigned int did, struct map_session_data* sd, struct map_session_data* target_sd);
	void (*accept) (const unsigned int did, struct map_session_data* sd);
	void (*reject) (const unsigned int did, struct map_session_data* sd);
	void (*leave) (const unsigned int did, struct map_session_data* sd);
	void (*showinfo) (const unsigned int did, struct map_session_data* sd);
	int (*checktime) (struct map_session_data* sd);

	void (*init) (bool minimal);
	void (*final) (void);
};

#ifdef HERCULES_CORE
void duel_defaults(void);
#endif // HERCULES_CORE

HPShared struct duel_interface *duel;

#endif /* MAP_DUEL_H */
