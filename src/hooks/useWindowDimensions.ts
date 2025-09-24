import { useState, useEffect } from 'react';
import type { WindowDimensions } from '../types';


export const useWindowDimensions = () => {
    const [windowDimensions, setWindowDimensions] = useState<WindowDimensions>({
        width: window.innerWidth,
        height: window.innerHeight
    });

    useEffect(() => {
        const handleResize = () => {
            setWindowDimensions({
                width: window.innerWidth,
                height: window.innerHeight
            });
        };

        window.addEventListener('resize', handleResize);
        return () => window.removeEventListener('resize', handleResize);
    }, []);

    return windowDimensions;
};