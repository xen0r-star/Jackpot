import { useState, useCallback, useImperativeHandle, forwardRef } from 'react';
import type { ScoreNotification } from '../types';
import { useWindowDimensions } from '../hooks';
import { GAME_CONFIG } from '../constants';


export interface ScoreNotificationsRef {
    addNotification: (points: number) => void;
}

const ScoreNotifications = forwardRef<ScoreNotificationsRef>((_, ref) => {
    const [notifications, setNotifications] = useState<ScoreNotification[]>([]);
    const windowDimensions = useWindowDimensions();

    const addNotification = useCallback((points: number) => {
        const notification: ScoreNotification = {
            id: Date.now() + Math.random(),
            points,
            x: Math.random() * (windowDimensions.width - 200) + 100,
            y: windowDimensions.height / 2 + Math.random() * 200 - 100,
            timestamp: Date.now()
        };
        
        setNotifications(prev => [...prev, notification]);
        
        setTimeout(() => {
            setNotifications(prev => prev.filter(n => n.id !== notification.id));
        }, GAME_CONFIG.SCORE_NOTIFICATION_DURATION);
    }, [windowDimensions]);

    useImperativeHandle(ref, () => ({
        addNotification
    }), [addNotification]);

    return (
        <>
            {notifications.map((notification) => (
                <div
                    key={notification.id}
                    className="fixed z-50 pointer-events-none animate-bounce"
                    style={{
                        left: `${notification.x}px`,
                        top: `${notification.y}px`,
                        animation: 'scorePopUp 2.5s ease-out forwards'
                    }}
                >
                    <div className="bg-gradient-to-r from-yellow-400 to-yellow-600 text-white font-bold text-3xl p-2 rounded-full shadow-lg border-4 border-yellow-300">
                        +{notification.points}
                    </div>
                </div>
            ))}
        </>
    );
});

ScoreNotifications.displayName = 'ScoreNotifications';

export default ScoreNotifications;