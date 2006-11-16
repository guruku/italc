/*
 * main.cpp - main-file for iTALC-setup-application
 *
 * Copyright (c) 2006 Tobias Doerffel <tobydox/at/users/dot/sf/dot/net>
 *
 * This file is part of iTALC - http://italc.sourceforge.net
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program (see COPYING); if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 */


#include <QtCore/QLocale>
#include <QtCore/QTranslator>
#include <QtGui/QApplication>

#include "dialogs.h"



// good old main-function... initializes qt-app and starts iTALC
int main( int argc, char * * argv )
{
	QApplication app( argc, argv );

	app.connect( &app, SIGNAL( lastWindowClosed() ), SLOT( quit() ) );


	// load translations
	const QString loc = QLocale::system().name().left( 2 );

	QTranslator app_tr;
	app_tr.load( ":/resources/" + loc + ".qm" );
	app.installTranslator( &app_tr );

	QTranslator qt_tr;
	qt_tr.load( ":/resources/qt_" + loc + ".qm" );
	app.installTranslator( &qt_tr );

	setupWizard sw;
	sw.show();

	// let's rock!!
	return( app.exec() );
}
