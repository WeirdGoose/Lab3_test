
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "MotrContr.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void FB_Regulator(struct FB_Regulator* inst)
{
	
	/*
	inst->integrator.in = inst->e * inst->k_i * inst->dt + inst->iyOld;	//integr's in (incoming signal e multipled by ki and dt adding old value)
	FB_Integrator(&(inst->integrator));			//calling integr
	
	inst->abs_in_1 = inst->e * inst->k_p;		//limiter's in
	
	if(inst->abs_in_1 > inst->max_abs_value || inst->abs_in_1 < -inst->max_abs_value)	//if in is equal or more than limit
		{
			if(inst->abs_in_1 > 0)
			{
				inst->abs_out_1 = inst->max_abs_value;	//than limit the value
			}
			else
			{
				inst->abs_out_1 = -inst->max_abs_value;	//than limit the value
			}
	}	
	else 										//else if in is less than limit
	{
		inst->abs_out_1 = inst->abs_in_1;		//than transmit the value to limiter's out
	}
	
	inst->abs_in_2 = inst->abs_out_1 + inst->integrator.out;	//transmit summ of integral and proport parts to limiter's in

	if(inst->abs_in_2 > inst->max_abs_value || inst->abs_in_2 < -inst->max_abs_value)		//if in is equal or more than limit
	{
		if(inst->abs_in_2 > 0)
		{
			inst->u = inst->max_abs_value;			//than limit the value and set to the outcoming signal u
		}
		else
		{
			inst->u = -inst->max_abs_value;			//than limit the value and set to the outcoming signal u
		}
	}
	else 										//else if in is less than limit
	{
		inst->u = inst->abs_in_2;				//than transmit the value to limiter's out and set to the outcoming signal u
	}
	
	inst->iyOld = inst->u - inst->abs_in_2;		//saving the current value
	
	
	*/
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	inst->integrator.in=inst->e * inst->k_i * inst->dt + inst->iyOld;
	
	FB_Integrator(&(inst->integrator));
	
	inst->e_kp=inst->e*inst->k_p;
	
	inst->e_kp=(inst->e_kp > inst->max_abs_value || inst->e_kp < - inst->max_abs_value)?((inst->e_kp>0)?inst->max_abs_value:-inst->max_abs_value):inst->e_kp;
	
	inst->e_kp+=inst->integrator.out;
	
	inst->u=(inst->e_kp > inst->max_abs_value || inst->e_kp < - inst->max_abs_value)?((inst->e_kp>0)?inst->max_abs_value:-inst->max_abs_value):inst->e_kp;
	
	inst->iyOld=inst->u-inst->e_kp;
	
	
	
	
	
	
	
	
}
