# This file is part of Hercules.
# http://herc.ws - http://github.com/HerculesWS/Hercules
#
# Copyright (C) 2012-2018  Hercules Dev Team
# Copyright (C)  Athena Dev Teams
#
# Hercules is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

# src/login/Makefile.  Generated from Makefile.in by configure.

CONFIG_D = ../config
CONFIG_H = $(wildcard $(CONFIG_D)/*.h) $(wildcard $(CONFIG_D)/*/*.h)

COMMON_D = ../common
COMMON_H = $(filter-out %.p.h, $(wildcard $(COMMON_D)/*.h)) ../plugins/HPMHooking.h
SYSINFO_INC = $(COMMON_D)/sysinfo.inc
COMMON_INCLUDE = -I..

THIRDPARTY_D = ../../3rdparty
THIRDPARTY_INCLUDE = -I$(THIRDPARTY_D)

LIBCONFIG_D = $(THIRDPARTY_D)/libconfig
LIBCONFIG_OBJ = $(addprefix $(LIBCONFIG_D)/, libconfig.o grammar.o scanctx.o \
                scanner.o strbuf.o)
LIBCONFIG_H = $(addprefix $(LIBCONFIG_D)/, libconfig.h grammar.h parsectx.h \
              scanctx.h scanner.h strbuf.h wincompat.h)

MT19937AR_D = $(THIRDPARTY_D)/mt19937ar
MT19937AR_OBJ = $(MT19937AR_D)/mt19937ar.o
MT19937AR_H = $(MT19937AR_D)/mt19937ar.h

LOGIN_C = account.c HPMlogin.c ipban.c lclif.c login.c loginlog.c
LOGIN_OBJ = $(addprefix obj_sql/, $(patsubst %.c,%.o,$(LOGIN_C)))
LOGIN_H = login.h account.h HPMlogin.h ipban.h lclif.h loginlog.h
LOGIN_PH = lclif.p.h

HAVE_MYSQL=yes
ifeq ($(HAVE_MYSQL),yes)
	LOGIN_SERVER_SQL_DEPENDS=$(LOGIN_OBJ) $(COMMON_D)/obj_all/common.a $(COMMON_D)/obj_sql/common_sql.a $(MT19937AR_OBJ) $(LIBCONFIG_OBJ) $(SYSINFO_INC)
else
	LOGIN_SERVER_SQL_DEPENDS=needs_mysql
endif



CC = gcc
export CC

#####################################################################
.PHONY: all sql login-server clean buildclean help

all: sql

sql: login-server

buildclean:
	@echo "	CLEAN	login (build temp files)"
	@rm -rf *.o obj_sql

clean: buildclean
	@echo "	CLEAN	login"
	@rm -rf ../../login-server

help:
	@echo "possible targets are 'login-server' 'all' 'clean' 'help'"
	@echo "'login-server' - login server"
	@echo "'all'          - builds all above targets"
	@echo "'clean'        - cleans builds and objects"
	@echo "'buildclean'   - cleans build temporary (object) files, without deleting the"
	@echo "                 executables"
	@echo "'help'         - outputs this message"

#####################################################################

Makefile: Makefile.in
	@$(MAKE) -C ../.. src/login/Makefile

$(SYSINFO_INC): $(LOGIN_C) $(LOGIN_PH) $(LOGIN_H) $(COMMON_H) $(CONFIG_H) $(MT19937AR_H) $(LIBCONFIG_H)
	@echo "	MAKE	$@"
	@$(MAKE) -C ../.. sysinfo

needs_mysql:
	@echo "MySQL not found or disabled by the configure script"
	@exit 1

# object directories

obj_sql:
	@echo "	MKDIR	obj_sql"
	@-mkdir obj_sql

# executables

login-server: ../../login-server

../../login-server: $(LOGIN_SERVER_SQL_DEPENDS) Makefile
	@echo "	LD	$(notdir $@)"
	@$(CC)   -rdynamic -fno-omit-frame-pointer -fno-var-tracking -o ../../login-server $(LOGIN_OBJ) $(COMMON_D)/obj_all/common.a $(COMMON_D)/obj_sql/common_sql.a \
		$(MT19937AR_OBJ) $(LIBCONFIG_OBJ) -lpcre -lpthread -lrt -lm -lz  -ldl -rdynamic -L/usr/lib64/mysql -lmysqlclient -lz -lcrypt -lnsl -lm -lssl -lcrypto

# missing object files
$(COMMON_D)/obj_all/common.a:
	@echo "	MAKE	$@"
	@$(MAKE) -C $(COMMON_D) sql

$(COMMON_D)/obj_sql/common_sql.a:
	@echo "	MAKE	$@"
	@$(MAKE) -C $(COMMON_D) sql

$(MT19937AR_OBJ):
	@echo "	MAKE	$@"
	@$(MAKE) -C $(MT19937AR_D)

$(LIBCONFIG_OBJ):
	@echo "	MAKE	$@"
	@$(MAKE) -C $(LIBCONFIG_D)

.SECONDEXPANSION:

# login object files

obj_sql/%.o: %.c $$(filter %.p.h, $(LOGIN_PH)) $(LOGIN_H) $(COMMON_H) $(CONFIG_H) $(MT19937AR_H) $(LIBCONFIG_H) | obj_sql
	@echo "	CC	$<"
	@$(CC) -g -O2 -std=c11 -pipe -ffast-math -Wall -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-clobbered -Wempty-body -Winit-self -Wpointer-arith -Wformat-security -Wformat -Wformat-y2k -Wsuggest-attribute=noreturn -Wundef -Wnested-externs -Wold-style-definition -Woverlength-strings -Wredundant-decls -Wcast-qual -Wno-format-nonliteral -Wno-switch -Wno-missing-field-initializers -Wno-suggest-attribute=format -Wshadow -fno-strict-aliasing -g -fno-omit-frame-pointer -fno-var-tracking -DHAVE_EXECINFO -DPACKAGE_NAME=\"\" -DPACKAGE_TARNAME=\"\" -DPACKAGE_VERSION=\"\" -DPACKAGE_STRING=\"\" -DPACKAGE_BUGREPORT=\"\" -DPACKAGE_URL=\"\" -DSTDC_HEADERS=1 -DHAVE_SYS_TYPES_H=1 -DHAVE_SYS_STAT_H=1 -DHAVE_STDLIB_H=1 -DHAVE_STRING_H=1 -DHAVE_MEMORY_H=1 -DHAVE_STRINGS_H=1 -DHAVE_INTTYPES_H=1 -DHAVE_STDINT_H=1 -DHAVE_UNISTD_H=1 -D__EXTENSIONS__=1 -D_ALL_SOURCE=1 -D_GNU_SOURCE=1 -D_POSIX_PTHREAD_SEMANTICS=1 -D_TANDEM_SOURCE=1 -DHAVE_USELOCALE=1 -DHAVE_NEWLOCALE=1 -DHAVE_FREELOCALE=1 -DHAVE_XLOCALE_H=1 -DHAVE_EXECINFO_H=1 $(COMMON_INCLUDE) $(THIRDPARTY_INCLUDE) -I/usr/include/mysql  -DMAXCONN=16384 -I../common -DHAS_TLS -DHAVE_SETRLIMIT -DHAVE_STRNLEN -DDEBUG -DHAVE_MONOTONIC_CLOCK -c $(OUTPUT_OPTION) $<
