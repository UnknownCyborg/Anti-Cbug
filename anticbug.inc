//======================================================================
/*
	Owner hell'hell'.
	vk.com/dykan_vallik.
	all rights reserved.
*/
//======================================================================
#if defined _anti_cbug_inc
  #endinput
#endif
#define _anti_cbug_inc
//======================================================================
#if !defined WARNING_CBUG
	#define WARNING_CBUG
#endif

#if !defined REMOVE_WEAPON
	//#define REMOVE_WEAPON
#endif

#if !defined ANTI_CBUG
	#define ANTI_CBUG
#endif

#if !defined MESSAGE_TO_CBUG
	#define MESSAGE_TO_CBUG
#endif
//======================================================================

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	#if defined ANTI_CBUG	
	    if((newkeys & (KEY_FIRE | KEY_CROUCH)) == (KEY_FIRE | KEY_CROUCH) && (oldkeys & (KEY_FIRE | KEY_CROUCH)) != (KEY_FIRE | KEY_CROUCH))
	    {
	    	new weapon = GetPlayerWeapon(playerid);
	        if(weapon == 24)
	        { 
	        	#if defined REMOVE_WEAPON
	        		ResetPlayerWeapons(playerid);
	        	#else
					SetPlayerArmedWeapon(playerid, 0);
				#endif
				#if defined MESSAGE_TO_CBUG
					GameTextForPlayer(playerid, !"~r~Stop C-Bug", 5000, 3);
				#endif
	 			ApplyAnimation(playerid, !"GYMNASIUM", !"gym_tread_falloff", 1.0, 0, 0, 0, 0, 0);
	 			#if defined WARNING_CBUG
	 				return printf("[Anti +C] Attempt +C Bug! ID[%d]!", playerid);
	 			#else
	 				return false;
	 			#endif
	        }
	    }
	#endif
    #if defined ANTI_OnPlayerKeyStateChange
    	return ANTI_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
    #else
    	return true;
    #endif
}
#if defined _ALS_OnPlayerKeyStateChange
	#undef OnPlayerKeyStateChange
#else
	#define OnPlayerKeyStateChange
#endif
#define OnPlayerKeyStateChange ANTI_OnPlayerKeyStateChange
#if defined ANTI_OnPlayerKeyStateChange
	forward ANTI_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
#endif
//======================================================================