/******************************************************************************
 * Copyright (C) 2015 Felix Rohrbach <kde@fxrh.de>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef QMATRIXCLIENT_ROOM_H
#define QMATRIXCLIENT_ROOM_H

#include <QtCore/QList>
#include <QtCore/QObject>
#include <QtCore/QJsonObject>

namespace QMatrixClient
{
    class Event;
    class State;
    class Connection;
    class User;

    class Room: public QObject
    {
            Q_OBJECT
        public:
            Room(Connection* connection, QString id);
            virtual ~Room();

            QString id() const;
            QList<Event*> messages() const;
            QString alias() const;
            QString topic() const;

            QList<User*> users() const;

            void addMessage( Event* event );
            void addInitialState( State* state );

        signals:
            void newMessage(Event* event);
            void aliasChanged(Room* room);
            void topicChanged();
            void userAdded(User* user);
            void userRemoved(User* user);

        private:
            class Private;
            Private* d;
    };
}

#endif // QMATRIXCLIENT_ROOM_H