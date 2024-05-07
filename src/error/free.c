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
    }
    //mlx_destroy_window(data->mlx, data->win);//確認すること
}

void free_data(t_data *data)
{
    free_images(data);
    free(data->mlx.mlx);
    free(data->mlx.win);
    free(data->mlx.img);
    free(data->mlx.addr);
    free(data->wall->ray_length);
    free(data->wall->collisions_dir);
    free(data->wall->wall_pos);
    free(data->wall->wall_height);
    free(data->map);
    free(data);
}