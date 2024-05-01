#include "cub_error.h"

void free_images(t_data *data)
{
    if (data->wall)
    {
        if (data->wall->no) {
            //mlx_destroy_image(data->mlx, data->wall->no->wall_image);
            free(data->wall->no);
        }
        if (data->wall->so) {
            //mlx_destroy_image(data->mlx, data->wall->so->wall_image);
            free(data->wall->so);
        }
         if (data->wall->we) {
            //mlx_destroy_image(data->mlx, data->wall->we->wall_image);
            free(data->wall->we);
        }
         if (data->wall->ea) {
            //mlx_destroy_image(data->mlx, data->wall->ea->wall_image);
            free(data->wall->ea);
        }
        free(data->wall);       
    }
    //mlx_destroy_window(data->mlx, data->win);//確認すること
}
