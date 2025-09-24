import React from 'react';
import type { ReelState } from '../types';
import { SYMBOLS } from '../constants';


interface SlotMachineProps {
    reels: ReelState[];
}

const SlotMachine: React.FC<SlotMachineProps> = ({ reels }) => {
    return (
        <div className="flex flex-col items-center">
            <div className="w-md h-40 px-8 bg-white border-[#FFCD1E] border-[14px] rounded-xl shadow-lg overflow-hidden relative flex">
                {reels.map((reel, index) => (
                    <div key={index} className="flex-1 relative">
                        {/* Window */}
                        <div className="absolute inset-0 flex items-center justify-center z-10">
                            <div className="w-20 h-20 flex items-center justify-center">
                                {!reel.isSpinning && (
                                    <img
                                        src={`/src/assets/symbole/${SYMBOLS[reel.currentSymbol]}.svg`}
                                        alt={SYMBOLS[reel.currentSymbol]}
                                        className="w-full h-full"
                                    />
                                )}
                            </div>
                        </div>

                        {/* Vertical scroll animation */}
                        {reel.isSpinning && (
                            <div className="absolute inset-0 overflow-hidden">
                                <div className="reel-scroll flex flex-col">
                                    {[...Array(20)].map((_, i) => (
                                        <div key={i} className="w-32 h-32 flex items-center justify-center flex-shrink-0">
                                            <img
                                                src={`/src/assets/symbole/${SYMBOLS[(reel.currentSymbol + i) % SYMBOLS.length]}.svg`}
                                                alt={SYMBOLS[(reel.currentSymbol + i) % SYMBOLS.length]}
                                                className="w-20 h-20"
                                            />
                                        </div>
                                    ))}
                                </div>
                            </div>
                        )}
                    </div>
                ))}

                {/* Left and right triangle */}
                <svg className='absolute right-0 top-1/2 -translate-y-1/2 translate-x-1.5' width="27" height="31" viewBox="0 0 27 31" fill="none" xmlns="http://www.w3.org/2000/svg">
                    <path d="M2.47589 12.1014C-0.044969 13.666 -0.0449668 17.334 2.47589 18.8986L20.8906 30.3278C23.5553 31.9816 27 30.0653 27 26.9291V4.07085C27 0.93473 23.5553 -0.981563 20.8906 0.672236L2.47589 12.1014Z" fill="#FFCD1E"/>
                </svg>
                <svg className='absolute left-0 top-1/2 -translate-y-1/2 -translate-x-1.5' width="27" height="31" viewBox="0 0 27 31" fill="none" xmlns="http://www.w3.org/2000/svg">
                    <path d="M24.5241 12.1014C27.045 13.666 27.045 17.334 24.5241 18.8986L6.10936 30.3278C3.44474 31.9816 0 30.0653 0 26.9291V4.07085C0 0.93473 3.44474 -0.981563 6.10936 0.672236L24.5241 12.1014Z" fill="#FFCD1E"/>
                </svg>

                {/* Faxe scrolling effect */}
                <div className="absolute top-0 left-0 right-0 h-4 bg-gradient-to-b from-white to-transparent z-20"></div>
                <div className="absolute bottom-0 left-0 right-0 h-4 bg-gradient-to-t from-white to-transparent z-20"></div>
            </div>
        </div>
    );
};

export default SlotMachine;